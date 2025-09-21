main() {
      int arr[10];
      fill(arr, arr+10, 3);
      
      int arr2[2][5];    
      fill(&arr2[0][0], &arr2[0][0]+10, 3);
      
      vector<int>arr3(10);
      fill(arr3.begin(), arr3.end(), 3);

      int low[n+10][K+10];    memset(low, 0x3f, sizeof(low));  // set 0x3f3f3f3f for all. This is a big positive number
      int upp[n+10][K+10];    memset(upp, 0xcf, sizeof(upp));  // set 0xcfcfcfcf for all. This is a big negative number.
}

// 如果 low 不是真正的二维数组（例如你用了 int** low 或 vector<vector<int>> low），那么 sizeof(low) 不会返回元素占用的总字节数（对于指针 it'll be pointer size），memset 的长度参数会不正确导致越界或只初始化了指针。如果使用动态分配/vector，请用 std::fill 或 fill_n
