int i = 0, j = 8;
  while (i <= j) {
    int sum = 0;
    for (int idx = i; idx <= j; i++) {
      sum += tall[idx];
    }
    cout << i << " " << j << " " << sum << '\n';
    if (sum == 100) {
      for (int idx = i; idx <= j; idx++) {
        cout << tall[idx] << "\n";
      }
      break;
    }
    if (sum > 100) {
      j--;
    } else {
      i++;
    }
  }