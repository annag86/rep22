// Урок1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
# include <cmath>
# include <cstdint>



// 1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
// Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate, который будет выводить результат
// возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.

class Power {

    double a;
    double b;

public:
    Power(double a = 3.9876, double b = 2.7) {
        this->a = a;
        this->b = b;
    }


    void setNum(double a, double b) {
        this->a = a;
        this->b = b;
    }

    void printSQRT() {

        std::cout << a << "^" << b << "=" << pow(a, b) << "\n\n";
    }

};


// 2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для 
// доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком 
// инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая
// будет выводить значения переменных-членов.


class RGBA {

    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) :m_red(int(red)), m_green(int(green)), m_blue(int(blue)),m_alpha(int(alpha)) {}
   
    void printRGBA() {
            std::cout << "m_red = " << int(m_red) << "\n" << "m_green = " << int(m_green) << "\n" <<  "m_blue = " << int(m_blue) << "\n" << "m_alpha = " << int(m_alpha) << "\n\n";
        }

};


/* 3. Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
      private - массив целых чисел длиной 10;
      private целочисленное значение для отслеживания длины стека;
      public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
      public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
      public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;
      public - метод с именем print(), который будет выводить все значения стека. 
*/


class Stack {

    int array[10];
    int length;

public:

    Stack() {
        for (int i=0; i<10; i++)
            array[i] =0;
        length = -1;
    
    }

    void reset() {
        
        for (int i = 0; i < 10; ++i)
            array[i] = 0;

        length = -1;


    }

    bool push(int a) {
        if (length < 9) {

            ++length;
            array[length] = a;
        }

        if (length == 9)
            return false;
        else
            return true;

}


    int pop(int pos) {
        
        

        if (array[10-pos] == 0 || pos > 10 || pos < 0)
        {
            setlocale(LC_ALL, "rus");
            std::cout << "В стеке нет значения для данной позиции. \n";
        }

        else
        {
            int temp = array[pos];
            for (int i = 10-pos; i < 9; ++i)
                array[i] = array[i + 1];
       
             array[9] = 0;

        return temp;
        }
        

    }



    void print() {

        for (int i = 0; i < 10; ++i)
        {
            std::cout<<array[i]<<" ";
            if (i == 9)
                std::cout << "\n";

        }
          
    }

};






int main()
{

    setlocale(LC_ALL, "rus");

    Power FirstResult;
    //FirstResult.setNum(5.904, 1.4);
    FirstResult.printSQRT();

    Power SecondResult;
   SecondResult.setNum(5.904, 1.4);
   SecondResult.printSQRT();


   RGBA firstObject;
   firstObject.printRGBA();

   RGBA secondObject(1, 2, 5, 120);
   secondObject.printRGBA();


   RGBA thirdObject(7, 10,50);
   thirdObject.printRGBA();



   Stack firststeck;
   firststeck.print();
   int a;
   bool b = true;


   while(b)
               {

       std::cout << "Введите значение для стека:\n";
       std::cin >> a;

       b=firststeck.push(int(a));

   }

    firststeck.print();

    firststeck.pop(4);
    firststeck.print();

    firststeck.pop(9);
    firststeck.print();


    return 0;
}












// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
