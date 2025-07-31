import pygame
from PPOIS.lab3.code.game_logic.settings import *

class Cat(pygame.sprite.Sprite):
    def __init__(self,groups,scale_factor):
        super().__init__(groups)

        self.import_frames(scale_factor)
        self.frame_index=0
        self.image=self.frames[self.frame_index]

        self.rect=self.image.get_rect(midleft=(WINDOW_WIDTH/8,WINDOW_HEIGHT/2))
        self.position=pygame.math.Vector2(self.rect.topleft)

        self.gravity=800
        self.direction=0

        self.mask = pygame.mask.from_surface(self.image)

        self.jump_sound=pygame.mixer.Sound('../sounds/jump.wav')
        self.jump_sound.set_volume(0.07)


    def import_frames(self,scale_factor):
        self.frames=[]
        for i in range(4):
            surf=pygame.image.load(f'../graphics/cat/cat{i+1}.png').convert_alpha()
            scaled_surface=pygame.transform.scale(surf,pygame.math.Vector2(surf.get_size())*scale_factor)
            self.frames.append(scaled_surface)


    def apply_gravity(self,dt):
        self.direction+=self.gravity*dt
        self.position.y+=self.direction*dt
        self.rect.y=round(self.position.y)


    def jump(self):
        self.jump_sound.play()
        self.direction=-400


    def animate(self,dt):
        self.frame_index+=10*dt
        if self.frame_index>=len(self.frames):
            self.frame_index=0
        self.image=self.frames[int(self.frame_index)]


    def rotate(self,):
        rotated_cat=pygame.transform.rotozoom(self.image,-self.direction*0.05,1)
        self.image=rotated_cat
        self.mask = pygame.mask.from_surface(self.image)


    def update(self,dt):
        self.apply_gravity(dt)
        self.animate(dt)
        self.rotate()
