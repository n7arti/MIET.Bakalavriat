//#include <iostream>
//#include <vector>
//#include <time.h>
//using namespace std;
//
//double function(int n)
//{
//	double ans;
//	if (n == 1.0) 
//		return(2.0 / 3.0);
//	ans = ((2* (double)function(double(n) - 1.0)) / 3.0); 
//	return(ans);
//}
//
//
//int main()
//{
//	vector<double> v;
//	clock_t time;
//	setlocale(LC_ALL, "ru");
//	int n;
//	cout << "Введите количество элементов массива: ";
//	cin >> n;
//
//	time = clock();
//	for (int i = 1; i < n; ++i)
//		v.push_back(function(i));
//	time = clock() - time;
//
//	for (auto i : v)
//		cout << i << "\n";
//	cout << endl;
//
//	printf("Время: %f секунд.\n", ((float)time) / CLOCKS_PER_SEC);
//	return 0;
//}
