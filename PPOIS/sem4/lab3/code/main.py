from PPOIS.lab3.code.game_logic.menu import *

if __name__=="__main__":
    while True:
        action = main_menu()

        if action == "start_game":
            game = Game()
            game.run()
        elif action == "quit":
            break
