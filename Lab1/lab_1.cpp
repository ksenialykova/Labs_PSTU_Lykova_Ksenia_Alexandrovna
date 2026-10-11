#include <iostream> 
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");
    
    //Задание 1
    cout << "Задание 1" << endl;
    
    // Тип float 
    float a_f = 100.0f;
    float b_f = 0.001f;

    // Промежуточные переменные числителя
    float c_f = pow(a_f-b_f, 4);
    float d_f = pow(a_f, 4) - 4 * pow(a_f, 3) * b_f + 6 * pow(a_f, 2) * pow (b_f, 2);
    float e_f = c_f - d_f;

    // Знаменатель 
    float h_f = pow(b_f, 4) - 4 * a_f * pow(b_f, 3);
    float res_f = e_f / h_f;

    cout << "Результат для float: " << res_f << endl;

    // Тип double 
    double a_d = 100.0;
    double b_d = 0.001;

    // Промежуточные переменные числителя
    double c_d = pow(a_d-b_d, 4);
    double d_d = pow(a_d, 4) - 4 * pow(a_d, 3) * b_d + 6 * pow(a_d, 2) * pow (b_d, 2);
    double e_d = c_d - d_d;

    // Знаменатель 
    double h_d = pow(b_d, 4) - 4 * a_d * pow(b_d, 3);
    double res_d = e_d / h_d;

    cout << "Результат для double: " << res_d << endl;
    cout << endl;

    //Задание 2
    cout << "Задание 2 " << endl;

    int n,m;

    cout <<  "Введите значение n: ";
    cin >> n;
    cout << "Введите значение m: ";
    cin >> m;

    cout << "Начальные значения: n = " << n << ", m = " << m << endl;

    // Выражение: n++ * m
    /* Постфиксный инкремент: сначала n умножается на m (используется старое значение n), затем n увеличивается 
    на 1 */
    int result1 = n++ * m;
    cout << "1) n++ * m = " << result1 << endl;
    cout << "Значение n после операции: " << n << endl;

    // Выражение: n++ < m
    /* Постфиксный инкремент: сначала n сравнивается с m (используется старое n), затем n увеличивается на 1, 
    и получаем логический результат сравнения (1 или 0) */
    bool result2 = n++ < m;
    cout << "2) n++ < m = " << result2 << endl;
    cout << "Значение n после операции: " << n << endl;

    // Выражение: m-- > m
    /* Постфиксный декремент: берем текущее значение m для левой части, m сразу же уменьшается на 1, 
    затем сравниваем левую часть (старое m) с правой частью (новое m), и получаем логичсекий результат (1 или 0) */
    bool result3 = m-- > m;
    cout << "3) m-- > m = " << result3 << endl;
    cout << "Значение m после операции: " << m << endl;


    return 0;
}
