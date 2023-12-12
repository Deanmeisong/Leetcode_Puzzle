class Solution(object):
    def validIPAddress(self, IP):
        """
        :type queryIP: str
        :rtype: str
        """
        def isIpv4(s):
            try: return str(int(s)) == s and 0 <= int(s) <= 255
            except: return False
        
        def isIpv6(s):
            try: return len(s) <= 4 and int(s, 16) >= 0
            except: return False
        
        if IP.count('.') == 3 and all(isIpv4(i) for i in IP.split('.')): return "IPv4"
        if IP.count(':') == 7 and all(isIpv6(i) for i in IP.split(':')): return "IPv6"
        
        return "Neither"