class VideoSharingPlatform {
public:
    VideoSharingPlatform() {
        ids.push(0);
    }
    
    int upload(string video) {
        int id = ids.top(); ids.pop();
        if(ids.empty()) ids.push(id + 1);
        content[id] = video;
        likes[id] = 0;
        dislikes[id] = 0;
        views[id] = 0;
        return id;
    }
    
    void remove(int videoId) {
        if(content.find(videoId) != content.end()) {
            content.erase(videoId);
            likes.erase(videoId);
            dislikes.erase(videoId);
            views.erase(videoId);
            ids.push(videoId);
        }
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if(content.count(videoId)) {
            string cont = content[videoId];
            int len = cont.length();
            if(startMinute >= len) return "-1";
            views[videoId]++;
            return cont.substr(startMinute, min(endMinute, len - 1) - startMinute + 1);
        }
        return "-1";

    }
    
    void like(int videoId) {
        if(likes.count(videoId)) likes[videoId]++;
    }
    
    void dislike(int videoId) {
        if(dislikes.count(videoId)) dislikes[videoId]++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if(dislikes.count(videoId)) return {likes[videoId], dislikes[videoId]};
        return {-1};
    }
    
    int getViews(int videoId) {
        if(views.count(videoId)) return views[videoId];
        return -1;
    }
       
    priority_queue<int, vector<int>, greater<>> ids;
    map<int, int> likes, dislikes, views;
    map<int, string> content;
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */