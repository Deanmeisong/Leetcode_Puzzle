/**
 * Definition for a street.
 * class Street {
 *     @param {number[]} doors
 *     constructor(doors);
 * 
 *     @return {void}
 *     closeDoor();
 * 
 *     @return {boolean}
 *     isDoorOpen();
 * 
 *     @return {void}
 *     moveRight();
 * }
 */
/**
 * @param {Street} street
 * @param {number} k
 * @return {number}
 */
var houseCount = function(street, k) {
    while(!street.isDoorOpen()) {
        street.moveRight();
    }
    let ans = 0;
    for(let i = 1; i <= k; ++i) {
        street.moveRight();
        if(street.isDoorOpen()) {
            ans = i;
            street.closeDoor();
        }
    }
    return ans;
};