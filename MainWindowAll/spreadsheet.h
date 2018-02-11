#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <QWidget>
#include <QTableWidget>


class Cell;
class SpreadsheetCompare;


namespace Ui {
class Spreadsheet;
}

class Spreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    explicit Spreadsheet(QWidget *parent = 0);
    ~Spreadsheet();
    bool autoRecalculate()const{ return autoRecalc;}
    QString currentLocation()const;
    QString currentFormula()const;
    QTableWidgetSelectionRange selectedRange()const;
    void clear();
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    void sort(const SpreadsheetCompare &compare);

public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();
    void recalculate();
    void setAutoRecalculate(bool recalc);
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPreviouse(const QString &str, Qt::CaseSensitivity cs);
signals:
    void modified();
private slots:
    void somethingChanged();

private:
    Ui::Spreadsheet *ui;
    enum{ MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };
    Cell *cell(int row, int column)const;
    QString text(int row, int column)const;
    QString formula(int row, int column)const;
    void setFormula(int row, int column, const QString &formula);

    bool autoRecalc;
};

class SpreadsheetCompare{
public:
    bool operator()(const QStringList &row1,
                    const QStringList &row2)const;
    enum{ KeyCount = 3};
    int keys[KeyCount];
    bool ascending[KeyCount];
};


#endif // SPREADSHEET_H

