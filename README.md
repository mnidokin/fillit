# Пояснительная записка
## Основная задумка
Мы решаем тетрис через ~~структуры~~ строки. Это должно быть быстрее и эффективнее по памяти.
Суть в хранении **координат тетриминошек**, которые мы выравниваем по верхнему левому краю,
записываем в массив int'ов. Потом мы конвертируем координаты для данного размера карты, а
дальше я пока не придумал.