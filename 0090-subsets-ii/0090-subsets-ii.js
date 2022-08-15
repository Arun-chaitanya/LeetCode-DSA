var subsetsWithDup = function(nums) {
  nums.sort(function(a, b){return a-b});
  var subFunc = function(numsArr, current=0, processed=[]) {
    if(numsArr.length === current){
    return [processed];
  }
  const avoided = subFunc(numsArr, current+1, processed);
  const included = subFunc(numsArr, current+1, [...processed,numsArr[current]]);
  return [...(numsArr[current] !== processed[processed.length - 1] ? avoided : []), ...included];
  }
  return subFunc(nums)
};