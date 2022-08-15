/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
  nums.sort(function(a, b){return a-b});
  var subFunc = function(numsArr, current=0, processed=[]) {
    if(numsArr.length === current){
    return [processed];
  }
  let avoided = subFunc(numsArr, current+1, processed);
  let included = subFunc(numsArr, current+1, [...processed,numsArr[current]]);
  
  return [...(numsArr[current] !== processed[processed.length - 1] ? avoided : []), ...included];
  }
  return subFunc(nums)
  
};