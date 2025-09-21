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
