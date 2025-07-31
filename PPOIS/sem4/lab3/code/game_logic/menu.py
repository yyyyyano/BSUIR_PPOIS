from PPOIS.lab3.code.game_logic.game import *
from PPOIS.lab3.code.game_logic.button import *
from PPOIS.lab3.code.game_logic.settings import *
import sys
from PPOIS.lab3.code.database.database import *

pygame.init()
os.environ['SDL_VIDEO_CENTERED'] = 'fl1'
screen = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
pygame.display.set_caption("Flappy cat menu")
image = pygame.image.load('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/environment/cosmos.png')
main_bg = pygame.transform.scale(image, (WINDOW_WIDTH, WINDOW_HEIGHT))
music = pygame.mixer.Sound('C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/sounds/promo_menu.mp3')
music.set_volume(0.2)

def help_menu():
    music.play()
    pygame.display.set_caption("Help - Rules of the Game")
    font_title = pygame.font.Font(None, 60)
    font_text = pygame.font.Font(None, 30)

    menu_button = ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 650, 252, 74,
                              "В главное меню",
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')

    clock = pygame.time.Clock()

    rules = [
        "Добро пожаловать в нашу игру!",
        "",
        "Цель игры:",
        "- Управляйте персонажем и избегайте столкновений с препятствиями.",
        "- Набирайте очки, преодолевая препятствия.",
        "",
        "Управление:",
        "- Нажимайте кнопку мыши для прыжков.",
        "- Используйте кнопки интерфейса для перезапуска игры или",
        "  выхода в меню."
    ]

    running = True
    while running:
        screen.fill((0, 0, 0))
        screen.blit(main_bg, (0, 0))

        title_surface = font_title.render("Правила игры", True, 'white')
        title_rect = title_surface.get_rect(center=(WINDOW_WIDTH / 2, 50))
        screen.blit(title_surface, title_rect)

        y_offset = 120
        for line in rules:
            text_surface = font_text.render(line, True, 'white')
            text_rect = text_surface.get_rect(topleft=(50, y_offset))
            screen.blit(text_surface, text_rect)
            y_offset += 40

        mouse_pos = pygame.mouse.get_pos()
        menu_button.check_hover(mouse_pos)
        menu_button.draw(screen)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                if menu_button.is_clicked(mouse_pos):
                    music.stop()
                    running = False

        pygame.display.update()
        clock.tick(60)


def show_records_menu(screen):
    music.play()
    pygame.display.set_caption("Table of Records")
    font_title = pygame.font.Font(None, 50)
    font_text = pygame.font.Font(None, 30)
    clock = pygame.time.Clock()

    menu_button = ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 650, 252, 74,
                              "В главное меню",
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')

    running = True
    records = get_all_records()

    while running:
        screen.fill((0, 0, 0))
        screen.blit(main_bg, (0, 0))

        title_surface = font_title.render("Таблица рекордов", True, 'white')
        title_rect = title_surface.get_rect(center=(400, 50))
        screen.blit(title_surface, title_rect)

        y_offset = 120
        line_height = 35

        for idx, (name, score) in enumerate(records[:15], start=1):
            record_text = f"{idx}. {name}: {score}"
            record_surface = font_text.render(record_text, True, 'white')
            record_rect = record_surface.get_rect(topleft=(50, y_offset))
            screen.blit(record_surface, record_rect)
            y_offset += line_height

        mouse_pos = pygame.mouse.get_pos()
        menu_button.check_hover(mouse_pos)
        menu_button.draw(screen)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
            if menu_button.is_clicked(mouse_pos):
                music.stop()
                running = False
                main_menu()

        pygame.display.flip()
        clock.tick(60)


def main_menu():


    new_game_button = ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 250, 252, 74,
                                  "Новая игра", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                                  'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')
    settings_button = ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 350, 252, 74,
                                  "Справка", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                                  'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')
    exit_button = ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 650, 252, 74,
                              "Выход", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')

    table_button=ImageButton(WINDOW_WIDTH / 2 - 252 / 2, 450, 252, 74,
                              "Таблица рекордов", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')

    buttons = [new_game_button, settings_button, exit_button,table_button]

    running = True
    while running:
        music.play(loops=-1)
        screen.fill((0, 0, 0))
        screen.blit(main_bg, (0, 0))

        font = pygame.font.Font(None, 72)
        text_surface = font.render("Flappy Bird", True, (255, 255, 255))
        text_rect = text_surface.get_rect(center=(WINDOW_WIDTH / 2, 100))
        screen.blit(text_surface, text_rect)

        for event in pygame.event.get():
            for btn in buttons:
                btn.handle_event(event)

            if event.type == pygame.QUIT:
                running = False
                pygame.quit()
                sys.exit()

            if event.type == pygame.MOUSEBUTTONDOWN:
                mouse_pos=pygame.mouse.get_pos()
                if new_game_button.is_clicked(mouse_pos):
                    music.stop()
                    return "start_game"

                elif settings_button.is_clicked(mouse_pos):
                    music.stop()
                    help_menu()

                elif table_button.is_clicked(mouse_pos):
                    music.stop()
                    show_records_menu(screen)

                elif exit_button.is_clicked(mouse_pos):
                    running = False
                    return "quit"

        for btn in buttons:
            btn.check_hover(pygame.mouse.get_pos())
            btn.draw(screen)

        pygame.display.flip()


def settings_menu():
    back_button = ImageButton(WINDOW_WIDTH / 2 - (252 / 2), 350, 252, 74,
                              "Back", 'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/purple_button.png',
                              'C:/Users/Bankevich/PycharmProjects/PythonProject/PPOIS/lab3/graphics/buttons/light_purple_button.png')

    running = True
    while running:
        screen.fill((0, 0, 0))
        screen.blit(main_bg, (0, 0))

        font = pygame.font.Font(None, 72)
        text_surface = font.render("Settings", True, (255, 255, 255))
        text_rect = text_surface.get_rect(center=(WINDOW_WIDTH / 2, 100))
        screen.blit(text_surface, text_rect)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                pygame.quit()
                sys.exit()

            if event.type == pygame.USEREVENT and event.button == back_button:
                running = False

            back_button.handle_event(event)

        back_button.check_hover(pygame.mouse.get_pos())
        back_button.draw(screen)

        pygame.display.flip()


def new_game():
    game = Game()
    while True:
        game.run()
