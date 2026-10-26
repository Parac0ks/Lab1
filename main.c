#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

// Математична функція f(x) за Варіантом 1
double f(double x) {
    return pow(x, 4) - 5 * pow(x, 3) - 0.25 * pow(x, 2) + 2;
}

int main() {
    // Встановлення системної кодування Windows для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int variant = 0;
    double X1 = 0.0, X2 = 0.0, delta = 0.0;
    int N = 0;

    // 1. Вибір способу введення
    printf("Оберіть варіант введення початкових даних:\n");
    printf("1 - X1, X2 та кількість точок N\n");
    printf("2 - X1, X2 та крок delta\n");
    printf("Ваш вибір (1 або 2): ");
    scanf("%d", &variant);

    // 2. Введення даних
    printf("Введіть X1: ");
    scanf("%lf", &X1);
    printf("Введіть X2: ");
    scanf("%lf", &X2);

    if (variant == 1) {
        printf("Введіть N: ");
        scanf("%d", &N);
        if (N < 2) N = 2;
        delta = (X2 - X1) / (N - 1);
    } else {
        printf("Введіть delta: ");
        scanf("%lf", &delta);
        if (delta <= 0) delta = 1.0;
        N = (int)((X2 - X1) / delta) + 1;
    }

    // 3. Шапка таблиці
    printf("\n+-----+--------------------+-------------------------+\n");
    printf("|  N  |         X          |          F(X)           |\n");
    printf("+-----+--------------------+-------------------------+\n");

    double f_prev = f(X1);
    int sign_changes = 0;
    int count = 0; // Лічильник рядків на екрані

    // ------------4. Цикл виводу таблиці-----------------------------
    for (int i = 1; i <= N; i++) {
        double current_x = X1 + (i - 1) * delta;
        double current_f = f(current_x);

        // Друк рядка
        printf("|%5d|%20.4f|%25.4f|\n", i, current_x, current_f);
        count++;

        // Посторінковий вивід по 10 рядків
        if (count == 10 && i < N) {
            printf("+-----+--------------------+-------------------------+\n");
            printf("Натисніть будь-яку клавішу для продовження...");
            getch();
            printf("\n");
            count = 0;
        }

        // Перевірка зміни знака
        if (i > 1) {
            if ((f_prev > 0 && current_f < 0) || (f_prev < 0 && current_f > 0)) {
                sign_changes++;
            }
        }

        f_prev = current_f;
    }

    printf("+-----+--------------------+-------------------------+\n");

    // 5. Результат
    printf("\nКількість змін знака функції: %d\n", sign_changes);

    return 0;
}
