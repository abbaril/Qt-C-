#ifndef MODEL_H
#define MODEL_H

#include <QMainWindow>

namespace Ui {
class Model;
}

class Model : public QMainWindow
{
    Q_OBJECT

public:
    explicit Model(QWidget *parent = 0);
    ~Model();

private:
    Ui::Model *ui;
};

#endif // MODEL_H
