#include <Engine/ParentState.h>
#include <Game/MenuState.h>
#include <UI/UIManager.h>
#include <UI/UIBox.h>

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
    _ui->addElement(new UIBox("background", Vector2(0.3f, 0.2f), Vector2(0.4f, 0.6f), "gray", 0.005f, "black"));


}

void MenuState::teardown() {
    Info("Tearing down MenuState");
}
