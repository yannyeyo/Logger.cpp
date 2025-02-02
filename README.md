# Тестовое задание для стажера на позицию «Разработчик C++» в компании Infotecs

## Цель

Разработать библиотеку для записи сообщений в журнал с разными уровнями важности и приложение, демонстрирующее работу библиотеки.

---

## Часть 1: Разработка библиотеки для записи сообщений в журнал

### Требования к библиотеке

1. **Динамическая библиотека**: Библиотека должна быть реализована как динамическая.
2. **Параметры инициализации**:
   - Имя файла журнала.
   - Уровень важности сообщений по умолчанию. Сообщения с уровнем ниже заданного не должны записываться в журнал. Рекомендуется использовать перечисление с понятными именами. Достаточно трех уровней важности: `INFO`, `WARNING`, `ERROR`.
3. **Журнал**: В журнале должны сохраняться следующие данные:
   - Текст сообщения.
   - Уровень важности.
   - Время получения сообщения.
4. **Изменение уровня важности**: После инициализации должна быть возможность изменять уровень важности сообщений по умолчанию.

---

## Часть 2: Разработка консольного многопоточного приложения

### Требования к приложению

1. **Использование библиотеки**: Приложение должно подключать и использовать библиотеку, реализованную в Части 1, для записи сообщений в журнал.
2. **Ввод пользователя**:
   - Приложение должно принимать от пользователя сообщение и его уровень важности через консоль. Уровень важности может быть не указан.
3. **Потокобезопасность**: Передача данных в журнал должна быть потокобезопасной.
4. **Многопоточность**: Приложение должно передавать принятые данные в отдельный поток для записи в журнал.
5. **Ожидание ввода**: После передачи данных приложение должно ожидать нового ввода от пользователя.
6. **Параметры приложения**:
   - Имя файла журнала.
   - Уровень важности сообщений по умолчанию.

### Внутренняя логика

Приложение должно поддерживать следующие функциональности:
- Получение данных от пользователя.
- Ведение журналирования с учетом уровня важности.
- Многопоточность для записи в журнал.

---

## Требования к выполнению задания

1. **Язык программирования**: Программный код должен быть написан на языке C++ стандарта C++17 с применением принципов ООП.
2. **Сборка проекта**:
   - Использовать Makefile для сборки проекта и тестирования.
   - Цели сборки для библиотеки и тестового приложения должны быть разделены.
   - В Makefile должна быть задана цель `clean` для очистки каталога от временных файлов.
   - Использовать компилятор `gcc` в среде Linux (Ubuntu/Debian).
3. **Чистота исходного кода**:
   - В папке с исходным кодом не должно быть ненужных файлов: неиспользуемых исходников, промежуточных файлов сборки и т.д.
4. **Отсутствие сторонних библиотек**: Не использовать сторонние библиотеки, за исключением стандартной библиотеки STL.
5. **Целевая операционная система**: Программа должна корректно работать на актуальных версиях Ubuntu/Debian.
6. **Обработка ошибок**: Приложение должно корректно обрабатывать ошибки, связанные с записью в файл журнала.
7. **Git-репозиторий**:
   - Все файлы (исходный код библиотеки и приложения, Makefile) должны быть размещены в одном git-репозитории.
   - Репозиторий должен быть доступен для проверки.

---