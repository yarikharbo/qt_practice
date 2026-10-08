#include "citygamedialog.h"
#include "ui_citygamedialog.h"
#include <QMessageBox>

CityGameDialog::CityGameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CityGameDialog)
{
    ui->setupUi(this);

    // Привязываем нажатие кнопки к нашему методу (слоту)
    QObject::connect(ui->sendButton, &QPushButton::clicked,
                     this, &CityGameDialog::ProcessTurn);

    ui->messageLabel->setText("Введите первый город!");
}

CityGameDialog::~CityGameDialog()
{
    delete ui;
}

void CityGameDialog::ProcessTurn() {
    QString city = ui->inputField->text().trimmed();

    if (city.isEmpty()) {
        return;
    }

    if (!IsValidMove(city)) {
        return;
    }

    UpdateGameState(city);
}

bool CityGameDialog::IsValidMove(const QString& city) const {
    // Проверка первой буквы (если это не первый ход)
    if (!history_.isEmpty()) {
        if (city.at(0).toLower() != last_char_.toLower()) {
            QMessageBox::warning(const_cast<CityGameDialog*>(this), "Ошибка",
                                 "Город должен начинаться на: " + QString(last_char_).toUpper());
            return false;
        }
    }

    // Проверка на повторы в истории
    for (const QString& historical_city : history_) {
        if (historical_city.compare(city, Qt::CaseInsensitive) == 0) {
            QMessageBox::information(const_cast<CityGameDialog*>(this), "Повтор", "Этот город уже был!");
            return false;
        }
    }

    return true;
}

void CityGameDialog::UpdateGameState(const QString& city) {
    // Добавляем в историю и выводим на экран
    history_.append(city);
    ui->historyList->addItem(city);

    // Вычисляем следующую букв у
    int last_index = city.length() - 1;
    last_char_ = city.at(last_index);

    // Исключаем ь, ъ, ы
    while ((last_char_ == QString("ь").at(0) ||
            last_char_ == QString("ъ").at(0) ||
            last_char_ == QString("ы").at(0)) && last_index > 0) {
        --last_index;
        last_char_ = city.at(last_index);
    }

    // Обновляем интерфейс для следующего хода
    ui->messageLabel->setText("Следующий город на: " + QString(last_char_).toUpper());
    ui->inputField->clear();
    ui->inputField->setFocus();
}