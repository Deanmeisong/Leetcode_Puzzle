class VideoSharingPlatform {
public:
    VideoSharingPlatform() {
        ids.push(0);
    }
    
    int upload(string video) {
        int id = ids.top();
        ids.pop();
        if (ids.empty())
            ids.push(id + 1);
        contents[id] = video;
        views[id] = 0;
        likes[id] = 0;
        dislikes[id] = 0;
        return id;
    }
    
    void remove(int videoId) {
        if (contents.count(videoId))
        {
            contents.erase(videoId);
            views.erase(videoId);
            likes.erase(videoId);
            dislikes.erase(videoId);
            ids.push(videoId);
        }
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (contents.count(videoId))
        {
            string content = contents[videoId];
            int len = content.length();
            if (startMinute >= len)
                return "-1";
            views[videoId]++;
            return content.substr(startMinute, min(len - 1, endMinute) - startMinute + 1);
        }
        return "-1";
    }
    
    void like(int videoId) {
        if (likes.count(videoId))
            likes[videoId]++;
    }
    
    void dislike(int videoId) {
        if (dislikes.count(videoId))
            dislikes[videoId]++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (contents.count(videoId))
            return {likes[videoId], dislikes[videoId]};
        return {-1};
    }
    
    int getViews(int videoId) {
        if (contents.count(videoId))
            return views[videoId];
        return -1;
    }
    
private: 
    priority_queue<int, vector<int>, greater<int>> ids;
    unordered_map<int, string> contents;
    unordered_map<int, int> views, likes, dislikes;
};