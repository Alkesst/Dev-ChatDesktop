#ifndef NEW_SERVER_WINDOW_H
#define NEW_SERVER_WINDOW_H

#include <QWidget>

namespace Ui {
class NewServerWindow;
}

class NewServerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewServerWindow(QWidget *parent = 0);
    ~NewServerWindow();

private:
    Ui::NewServerWindow *ui;
};

#endif // NEW_SERVER_WINDOW_H
