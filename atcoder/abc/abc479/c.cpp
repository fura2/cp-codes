#include "template/template.hpp"

// #define MULTI_TESTCASE
#include "template/main.hpp"
#include "typical/knapsack_01.hpp"

void testcase() {
  auto n = input<int>();
  auto w = input<lint>();
  vector<lint> a(n), b(n);
  rep (i, n) {
    a[i] = input<lint>();
    b[i] = input<lint>();
  }
  output(knapsack_01(b, a, w, KnapsackAlgorithm::MeetInTheMiddle));
}
