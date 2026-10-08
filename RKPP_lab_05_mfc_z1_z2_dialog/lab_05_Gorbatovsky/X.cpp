#include "pch.h"
#include "X.h"
#include <cmath>
#include <afxwin.h> 

X::X() : m_m(0.0), m_z1(0.0), m_z2(0.0) {}

X::~X() {}

void X::set(double m) {
    m_m = m;
    AfxMessageBox(_T("Объект создан и проинициализирован!"));
}

void X::run() {

    if (m_m <= 0.0) {
        AfxMessageBox(_T("Ошибка: m должно быть строго больше 0!"));
        m_z1 = 0.0;
        m_z2 = 0.0;
        return;
    }

    double denominator = 3.0 * std::sqrt(m_m) - 2.0 / std::sqrt(m_m);
    if (std::abs(denominator) < 1e-9) {
        AfxMessageBox(_T("Ошибка: Знаменатель обращается в ноль (m = 2/3)!"));
        m_z1 = 0.0;
        m_z2 = 0.0;
        return;
    }

    double numerator_expr = std::pow(3.0 * m_m + 2.0, 2.0) - 24.0 * m_m;
    double numerator = std::sqrt(numerator_expr);

    m_z1 = numerator / denominator;
    m_z2 = -std::sqrt(m_m);
}

void X::print() const {
    CString str;
    str.Format(_T("Результаты вычислений:\nm = %.4f\nz1 = %.4f\nz2 = %.4f"),
        m_m, m_z1, m_z2);
    AfxMessageBox(str);
}