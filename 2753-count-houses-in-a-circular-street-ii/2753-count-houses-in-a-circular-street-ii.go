/**
 * Definition for a street.
 * type Street interface {
 *     CloseDoor()
 *     IsDoorOpen() bool
 *     MoveRight()
 * }
 */
func houseCount(street Street, k int) int {
    for !street.IsDoorOpen() {
        street.MoveRight()
    }
    var ans int = 0
    for i:=1; i<=k; i++ {
        street.MoveRight()
        if street.IsDoorOpen() {
            ans = i;
            street.CloseDoor()
        }
    }
    return ans
}