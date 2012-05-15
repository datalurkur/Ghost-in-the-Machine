#include <Engine/ParentState.h>
#include <Game/MenuState.h>
#include <UI/UIManager.h>
#include <UI/UIBox.h>
#include <UI/UIText.h>
#include <UI/UIButton.h>

MenuState::MenuState() {
}

MenuState::~MenuState() {
}

bool MenuState::update(int elapsed) {
    _ui->update();

    return true;
}

bool MenuState::render(RenderContext *renderContext) {
    _ui->render(renderContext);

    return true;
}

void MenuState::setup(va_list args) {
    Info("Setting up MenuState");
    _ui = va_arg(args, UIManager*);

    // Set up menu objects

    // Background box
    _ui->addElement(new UIBox("background", Vec2f(0.3f, 0.2f), Vec2f(0.4f, 0.6f), "gray", 0.005f, "black"));

    // Title text
    _ui->addElement(new UIText("title", Vec2f(0.3f, 0.64f), Vec2f(0.4f, 0.16f), "Ghost in the Machine", "title", Font::CENTER));

    // Buttons
    UIButton *newGameButton = new UIButton("new_game_button", Vec2f(0.32f, 0.56f), Vec2f(0.36f, 0.06f), "gray", 0.005f, "black");
    // Setup button press callback
    //newGameButton->
    _ui->addElement(newGameButton);

    // Refresh cached values
    update(0);
}

void MenuState::teardown() {
    Info("Tearing down MenuState");
}
