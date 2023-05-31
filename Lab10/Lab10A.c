#include <stdio.h>//Підключаємо бібліотеку

//Функція для видалення рядка з початку текстового файлу
void deleteFirstLine(const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "r+") != 0) {
        printf("Помилка відкриття файлу.\n");
        return;
    }

    //Зчитування першого рядка
    int c;
    while ((c = getc(file)) != EOF) {
        if (c == '\n') {
            break;
        }
    }

    //Зсув вмісту файлу на початок
    FILE* temp;
    if (fopen_s(&temp, "temp.txt", "w") != 0) {
        printf("Помилка створення тимчасового файлу.\n");
        fclose(file);
        return;
    }

    while ((c = getc(file)) != EOF) {
        putc(c, temp);//Копіювання решти файлу в тимчасовий файл
    }

    //Закриття файлів
    fclose(file);
    fclose(temp);

    //Видалення вихідного файлу
    remove(filename);

    //Перейменування тимчасового файлу на вихідний
    rename("temp.txt", filename);

    printf("\x1b[35mпуф...\n\x1b[0m");
}

int main() {
    int n;//Оголошуємо змінну
    printf("Введіть кількість чисел: ");//Ввід кількості чисел з клавіатури
    scanf_s("%d", &n);

    FILE* file;
    if (fopen_s(&file, "додатні_числа.txt", "w") != 0) {//Створеня файлу 
        printf("Помилка відкриття файлу.\n");//Помилка у випадку якщо з файлом щось не так
        return 1;
    }

    int number = 2;
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", number);
        number += 2;
    }

    fclose(file);
    printf("Файл успішно створений та заповнений додатніми числами.\n");//Повідомленя на екран юзера якщо файл був сворений

    int choice;//Вибір чи буде працювати функція для видалення рядка з початку текстового файлу
    printf("Виконати таємну функцію?\n");
    printf("1. Так\n");
    printf("2. Ні\n");
    scanf_s("%d", &choice);
    

    if (choice == 1) {
        deleteFirstLine("додатні_числа.txt");
        printf("Рядок з початку був видалений.\n");//Варіант "так"
    }
    else {
        printf("Виконання таємної функції скасовано.\n");//Варіант"Ні"
    }

    return 0;//Кінець програми...
}
