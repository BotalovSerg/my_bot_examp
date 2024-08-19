const joinNumbersFromRange = (start, finish) => {
    let res = "";
    while (start <= finish) {
      res = `${res}${start}`;
      start += 1;
    }
    return res;
  };

  console.log(joinNumbersFromRange(5, 10));