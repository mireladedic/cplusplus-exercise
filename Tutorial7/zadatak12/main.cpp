
#include<iostream>
#include<string>
#include<set>
#include<memory>
#include <algorithm>

using namespace std;
template <typename T, typename F>
 void f(T p, T q, F r) { while(p != q) r(*--q); }
 auto g(int &p, int q, int &r) -> decltype(p) {   p += q; q += r; r += p;   std::cout << p << " " << q << " " << r << std::endl;   return p; }
 void h(int **p, std::shared_ptr<int> q) { *p = q.get(); }
 std::function<int(int)> w(int x) { return [x](double y) { return 2 * x - y; }; }
 int main() {   int a[] {3, 7, 2, 9, 6, 5}, *p(a + 2), q(6), r(3);   int *m(&a[3]), &n(*m);   auto z(w(q + r)); m += 2;   std::cout << z(q - r) << std::endl;   std::shared_ptr<int> u, v;   std::string str{"a ba"};   f(a, a + 5, [&r](int x) { std::cout << x << "," << r << " "; r += x; });   std::cout << std::endl << r << std::endl;   g(*(a + 2), a[4], p[-2]) *= 2;   for(int p : a) p += 3;   for(int p : a) std::cout << p << " ";   std::cout << std::endl;   u = std::shared_ptr<int>(new int(q)); v = std::make_shared<int>(2);   h(&p, u); std::cout << p[0] << " " << n << " ";   h(&p, v); std::cout << str << " ";   std::remove_copy(str.rbegin(), str.rend(), std::back_inserter(str), ' ');   std::cout << str << std::endl; std::cout << p[0] << std::endl;   for(int &k : a) k += 3; for(int k : a) std::cout << k << " ";   std::cout << std::endl;   std::set<int> s;   s.insert(5); s.insert(3); s.insert(5); s.insert(2);   for(auto i = s.begin(); i != s.end(); i++) std::cout << *i << " ";   return 0; }
