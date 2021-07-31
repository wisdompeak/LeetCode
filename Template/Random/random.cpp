mt19937 gen{random_device{}()};
int left = 1, right = 100;
int r = uniform_int_distribution<int>{left, right}(gen);
