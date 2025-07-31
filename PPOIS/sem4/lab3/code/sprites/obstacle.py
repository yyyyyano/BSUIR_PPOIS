import pygame
from PPOIS.lab3.code.game_logic.settings import *
from random import *

class Obstacle(pygame.sprite.Sprite):
    def __init__(self,groups,scale_factor):
        super().__init__(groups)
        self.sprite_type='obstacle'

        orientation=choice(('up','down'))
        surf=pygame.image.load(f'../graphics/rocket/rocket{choice((0,2))+1}.png').convert_alpha()
        self.image=pygame.transform.scale(surf,pygame.math.Vector2(surf.get_size())*scale_factor*2.1)

        x=WINDOW_WIDTH+randint(40,100)


        if orientation=='up':
            y=WINDOW_HEIGHT+randint(10,50)
            self.rect=self.image.get_rect(midbottom=(x,y))
        else:
            y=randint(-50,-10)
            self.image=pygame.transform.flip(self.image,False,True)
            self.rect=self.image.get_rect(midtop=(x,y))
        self.position=pygame.math.Vector2(self.rect.topleft)

        self.mask = pygame.mask.from_surface(self.image)


    def update(self,dt):
        self.position.x-=400*dt
        self.rect.x=round(self.position.x)

        if self.rect.right<=-100:
            self.kill()
