main() {
      int arr[10];
      fill(arr, arr+10, 3);
      
      int arr2[2][5];    
      fill(&arr2[0][0], &arr2[0][0]+10, 3);
      
      vector<int>arr3(10);
      fill(arr3.begin(), arr3.end(), 3);
}
