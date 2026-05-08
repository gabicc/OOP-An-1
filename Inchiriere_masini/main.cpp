// #include <iostream>
//
// #include "Console.h"
// #include "TestMasina.h"
//
// int main() {
//     test_masina_all();
//     test_masina_serviciu_all();
//     run_console();
//     return 0;
//     // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
// }

#include <QtWidgets/QDialog>
#include <QtWidgets/QApplication>

#include "InchiriereGUI.h"
#include "RepoMasiniMap.h"


class MasiniWindow :  public QWidget {
public:
    MasiniWindow(QWidget* parent = nullptr);
private:
    // Button *::createButton(const QString &text, const char *member);
};

MasiniWindow::MasiniWindow(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("Inchirieri Masini");

    // Make widgets, etc...
}

// Button *MasiniWindow::createButton(const QString &text, const char *member)
// {
//     Button *button = new Button(text);
//     connect(button, SIGNAL(clicked()), this, member);
//     return button;
// }


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    app.setApplicationName("Inchirieri Masini");
    Repo* repo = new RepoMasiniMap(0.0);
    Service srv(repo);
    auto win = new InchiriereGUI(srv);
    //auto wim = new MasiniWindow();
    win->show();

    return app.exec();
}