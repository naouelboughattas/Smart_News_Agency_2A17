#include <QMainWindow>

namespace Ui {
class TinyScreenshoter;
}

class TinyScreenshoter : public QMainWindow
{
    Q_OBJECT

public:
    explicit TinyScreenshoter(QWidget *parent = 0);
    ~TinyScreenshoter();

protected:

private slots:

private:
    Ui::TinyScreenshoter *ui;
};
