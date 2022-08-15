var subsetsWithDup = function(nums) {
  nums.sort(function(a, b){return a-b});
  var subFunc = function(numsArr, current=0, processed=[]) {
    if(numsArr.length === current){
      return [processed];
    }
    let avoided = [];
    const included = subFunc(numsArr, current+1, [...processed,numsArr[current]]);
    if(numsArr[current] !== processed[processed.length - 1]){
      avoided = subFunc(numsArr, current+1, processed);
    }
    return [...avoided, ...included];
  }
  return subFunc(nums)
};