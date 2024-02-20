main() {
  int arr[10];
  fill(arr, arr+10, 3);
  for (int i=0; i<10; i++) cout<<arr[i]<<" "; cout<<endl;

  // Underfined Behavior on LeetCode
  int arr2[5][2];    
  fill(arr2[0], arr2[0]+10, 3);
  for (int i=0; i<2; i++)
      for (int j=0; j<5; j++) 
          cout<<arr2[i][j]<<" "; 
  cout<<endl;

  vector<int>arr3(10);
  fill(arr3.begin(), arr3.end(), 3);
  for (int i=0; i<10; i++) cout<<arr3[i]<<" "; cout<<endl;
}
