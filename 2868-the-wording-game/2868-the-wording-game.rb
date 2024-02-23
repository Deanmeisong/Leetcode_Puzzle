# @param {String[]} a
# @param {String[]} b
# @return {Boolean}
def can_alice_win(a, b)
    w, i, j, k= a[0], 1, 0, 1
    while true do
        if k == 1
            return true if j == b.length
            if w[0] == b[j][0] && w < b[j] || b[j][0].ord - w[0].ord == 1
                w = b[j]
                k ^= 1
            end
            j += 1
        else
            return false if i == a.length
            if w[0] == a[i][0] && w < a[i] || a[i][0].ord - w[0].ord == 1
                w = a[i]
                k ^= 1
            end
            i += 1
        end
    end
end