#ifndef MULTIDOCUMENT_H
#define MULTIDOCUMENT_H

#include <QMainWindow>

namespace Ui {
class MultiDocument;
}

class MultiDocument : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiDocument(QWidget *parent = 0);
    ~MultiDocument();

private:
    Ui::MultiDocument *ui;
    QWorkSpace *workSpace;
};

#endif // MULTIDOCUMENT_H
