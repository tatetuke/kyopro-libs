/*
•¶š—ñS‚Ì•”•ª•¶š—ñS[i,S.size()]‚É‚¨‚¯‚éÅ’·Ú“ª«
aaabaaaab
921034210


ACL‚ğg‚¨‚¤
https://atcoder.github.io/ac-library/production/document_ja/string.html




https://ei1333.github.io/luzhiled/snippets/string/z-algorithm.html


vector< int > z_algorithm(const string &s) {
  vector< int > prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i - j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    } else {
      int k = max(0, j + prefix[j] - i);
      while(i + k < s.size() && s[k] == s[i + k]) ++k;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}

*/