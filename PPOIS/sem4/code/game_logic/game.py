import sys,time
from PPOIS.lab3.code.database.database import get_max_score, update_records
from PPOIS.lab3.code.game_logic.settings import *
from PPOIS.lab3.code.sprites.cat import *
from PPOIS.lab3.code.sprites.ground import *
from PPOIS.lab3.code.sprites.obstacle import *
from PPOIS.lab3.code.sprites.background import *
from PPOIS.lab3.code.game_logic.button import *

class Game:
    def __init__(self):
        pygame.init()
        self.display_surface=pygame.display.set_mode((WINDOW_WIDTH,WINDOW_HEIGHT))
        pygame.display.set_caption('Flappy cat')
        self.clock=pygame.time.Clock()
        self.active=True

        self.all_sprites=pygame.sprite.Group()
        self.collision_sprites=pygame.sprite.Group()

        bg_height=pygame.image.load('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/background.jpg').get_height()
        self.scale_factor=WINDOW_HEIGHT/bg_height

        BG(self.all_sprites,self.scale_factor)
        Ground([self.all_sprites,self.collision_sprites],self.scale_factor)
        self.cat=Cat(self.all_sprites,self.scale_factor/6)

        self.obstacle_timer=pygame.USEREVENT+1
        pygame.time.set_timer(self.obstacle_timer,1400)

        self.font=pygame.font.Font('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/font/BD_Cartoon_Shout.ttf', 30)
        self.score=0
        self.start_offset=0

        game_over_surface = pygame.image.load('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/game_over.png').convert_alpha()
        self.game_over_surface = pygame.transform.scale(game_over_surface,
                                                       pygame.math.Vector2(game_over_surface.get_size()) * 1.8)
        self.game_over_rect = self.game_over_surface.get_rect(center=(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 -300))

        self.restart_button=ImageButton(WINDOW_WIDTH / 2 - 252 / 2 + 25, WINDOW_HEIGHT / 2 - 50, 200, 200,
                                  "", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/restart_button.png',
                                  '../graphics/buttons/light_restart_button.png')

        self.to_menu_button=ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 600, 252, 74,
                                  "В главное меню", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                                  'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')

        self.music=pygame.mixer.Sound('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/sounds/tututu.mp3')
        self.music.set_volume(0.3)
        self.music.play(loops=-1)
        self.obstacle_music=pygame.mixer.Sound('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/sounds/raketaaa.wav')
        self.obstacle_music.set_volume(0.3)


    def collisions(self):
        if pygame.sprite.spritecollide(self.cat, self.collision_sprites, False, pygame.sprite.collide_mask) \
                or self.cat.rect.top <= 0:
            for sprite in self.collision_sprites.sprites():
                if sprite.sprite_type == 'obstacle':
                    self.music.stop()
                    sprite.kill()

            self.active = False
            self.cat.kill()

            max_score_record = get_max_score()
            if max_score_record is None or self.score > max_score_record:
                name = self.show_high_score_dialog(self.score)
                if name:
                    update_records(name, self.score)
                    print(f"New high score! {name} with {self.score} points!")


    def show_high_score_dialog(self, score):
        image = pygame.image.load('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/environment/cosmos.png')
        main_bg = pygame.transform.scale(image, (WINDOW_WIDTH, WINDOW_HEIGHT))

        font_title = pygame.font.Font(None, 60)
        font_text = pygame.font.Font(None, 40)
        input_box = pygame.Rect(200, 300, 400, 50)

        color_inactive = pygame.Color('lightskyblue3')
        color_active = pygame.Color('dodgerblue2')
        color = color_inactive
        active = False

        clock = pygame.time.Clock()
        name = ""
        running = True

        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    exit()
                if event.type == pygame.MOUSEBUTTONDOWN:
                    if input_box.collidepoint(event.pos):
                        active = not active
                    else:
                        active = False
                    color = color_active if active else color_inactive
                if event.type == pygame.KEYDOWN:
                    if active:
                        if event.key == pygame.K_RETURN:
                            return name
                        elif event.key == pygame.K_BACKSPACE:
                            name = name[:-1]
                        else:
                            name += event.unicode

            self.display_surface.blit(main_bg, (0, 0))

            title_surface = font_title.render("Поздравляем с новым рекордом!", True, 'white')
            title_rect = title_surface.get_rect(center=(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 300))
            self.display_surface.blit(title_surface, title_rect)

            score_surface = font_text.render(f"Ваш счёт: {score}", True, 'white')
            score_rect = score_surface.get_rect(center=(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 200))
            self.display_surface.blit(score_surface, score_rect)

            prompt_surface = font_text.render("Введите ваше имя:", True, 'white')
            prompt_rect = prompt_surface.get_rect(center=(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 100))
            self.display_surface.blit(prompt_surface, prompt_rect)

            input_text = font_text.render(name, True, 'white')
            input_box.w = max(WINDOW_WIDTH/2, input_text.get_width() + 10)
            input_box.y = prompt_rect.bottom + 20
            self.display_surface.blit(input_text, (input_box.x + 30, input_box.y + 5))
            pygame.draw.rect(self.display_surface, color, input_box, 2)

            pygame.display.flip()
            clock.tick(30)


    def display_score(self):
        if self.active:
            if self.start_offset == 0:
                self.start_offset = pygame.time.get_ticks()

            self.score = (pygame.time.get_ticks() - self.start_offset) // 100
            x, y = 100, 50
        else:
            x, y = WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - 120
            text_score_surf = self.font.render('Your score', True, 'white')
            text_score_rect = text_score_surf.get_rect(midtop=(x, y - 40))
            self.display_surface.blit(text_score_surf, text_score_rect)

        score_surf = self.font.render(str(self.score), True, 'white')
        score_rect = score_surf.get_rect(midtop=(x, y))

        self.display_surface.blit(score_surf, score_rect)


    def run(self):
        last_time = time.time()
        running = True
        while running:
            dt = time.time() - last_time
            last_time = time.time()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    pygame.quit()
                    sys.exit()

                self.to_menu_button.handle_event(event)
                self.restart_button.handle_event(event)

                if event.type == pygame.MOUSEBUTTONDOWN or event.type == pygame.KEYDOWN:
                    if self.active:
                        self.cat.jump()

                    else:
                        mouse_pos = pygame.mouse.get_pos()
                        if self.restart_button.is_clicked(mouse_pos):
                            self.music.play()
                            self.cat = Cat(self.all_sprites, self.scale_factor / 6)
                            self.active = True
                            self.score = 0
                            self.start_offset = pygame.time.get_ticks()
                            break
                        elif self.to_menu_button.is_clicked(mouse_pos):
                            running = False
                            return

                if event.type == self.obstacle_timer and self.active:
                    Obstacle([self.all_sprites, self.collision_sprites], self.scale_factor * 1.2)

            self.display_surface.fill('black')

            if self.active:
                self.all_sprites.update(dt)
                self.collisions()

            self.all_sprites.draw(self.display_surface)
            self.display_score()

            if not self.active:
                self.restart_button.check_hover(pygame.mouse.get_pos())
                self.restart_button.draw(self.display_surface)
                self.display_surface.blit(self.game_over_surface, self.game_over_rect)
                self.to_menu_button.check_hover(pygame.mouse.get_pos())
                self.to_menu_button.draw(self.display_surface)

            pygame.display.update()
            self.clock.tick(FRAMERATE)


    def clean_game_state(self):
        self.all_sprites.empty()
        self.collision_sprites.empty()
        self.active = False
        self.score = 0