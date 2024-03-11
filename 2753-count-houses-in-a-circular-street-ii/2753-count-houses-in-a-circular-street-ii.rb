# Definition for a street.
# class Street
#   def initialize(doors)
#   end
#   def close_door
#   end
#   def is_door_open
#   end
#   def move_right
#   end
# end
# @param {Street} street
# @param {Integer} k
# @return {Integer}
def house_count(street, k)
    until street.is_door_open
        street.move_right
    end
    ans = 0
    (1..k).each do |i|
        street.move_right
        if street.is_door_open
            ans = i
            street.close_door
        end
    end
    ans
end