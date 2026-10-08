#ifndef CITYGAMEDIALOG_H
#define CITYGAMEDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QString>
#include <QChar>

namespace Ui {
class CityGameDialog;
}

class CityGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CityGameDialog(QWidget *parent = nullptr);
    ~CityGameDialog();

private slots:
    void ProcessTurn(); // Обработчик кнопки отправки

private:
    Ui::CityGameDialog *ui;

    // Вспомогательные методы
    bool IsValidMove(const QString& city) const;
    void UpdateGameState(const QString& city);

    // Переменные состояния
    QStringList history_;
    QChar last_char_;
};

#endif // CITYGAMEDIALOG_H