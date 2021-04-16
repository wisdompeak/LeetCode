// read a series of words in str seperated by blanks
vector<string> ReadWordsFromString(string str)
{
  vector<string>str_arr;
  istringstream in(str);
  int k = 0;
  for (string word; in>>word; k++) 
      str_arr.push_back(word);
  return str_arr;
}

