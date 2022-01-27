function subsets(n) {
    var result = 0;
    for (var i = 0; i < Math.pow(2, n); i++) {
      var bitmask = i.toString(2);
      while (bitmask.length < n) {
        bitmask = '0' + bitmask;
      }
      var subset = [];
      for (var j = 0; j < n; j++) {
        if (bitmask[j] == '1') {
          subset.push(j);
        }
      }
      result += subset.length;
    }
    return result;
  }
console.log(subsets(4))  