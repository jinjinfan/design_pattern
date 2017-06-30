//
// Created by claudia on 2017/6/25.
//

#ifndef ADAPTER_GEOMETRY_H
#define ADAPTER_GEOMETRY_H

#include <vector>
#include <boost/functional/hash_fwd.hpp>
#include <map>
#include <boost/functional/hash.hpp>

struct Point {
    int x, y;
    friend std::size_t hash_value(const Point& obj) {
        size_t seed = 0x1E44943F;
        boost::hash_combine(seed, obj.x);
        boost::hash_combine(seed, obj.y);
        return seed;
    }
};

struct Line {
    Point start, end;
    friend std::size_t hash_value(const Line& obj) {
        size_t seed = 0x52E4F07A;
        boost::hash_combine(seed, obj.start);
        boost::hash_combine(seed, obj.end);
        return seed;
    }
};

struct VectorObject {
    virtual std::vector<Line>::iterator begin() = 0;
    virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject {
    VectorRectangle(int x, int y, int width, int height) {
        lines.emplace_back(Line{Point{x, y}, Point{x+width, y}});
        lines.emplace_back(Line{Point{x + width, y}, Point{x+width, y+height}});
        lines.emplace_back(Line{Point{x, y}, Point{x, y + height}});
        lines.emplace_back(Line{Point{x, y+height}, Point{x+width, y+height}});
    }

    std::vector<Line>::iterator begin() override {
        return lines.begin();
    }

    std::vector<Line>::iterator end() override {
        return lines.end();
    }

private:
    std::vector<Line> lines;
};

struct LineToPointAdapter {
    typedef vector<Point> Points;

    LineToPointAdapter(Line& line) {
        static int count = 0;
        cout << count << " generating points to line" << endl;
        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;
        // Vertical
        if (dx == 0) {
            for (int idx = top; idx <= bottom; ++idx) {
                points.emplace_back(Point{left, idx});
            }
        } else if (dy == 0) {
            for (int idx = left; idx <= right ; ++idx) {
                points.emplace_back(Point{idx, top});
            }
        }
    }
    virtual Points::iterator begin() {
        return points.begin();
    }
    virtual Points::iterator end() {
        return points.end();
    }
private:
    Points points;
};

struct LineToPointCachingAdapter {
    typedef vector<Point> Points;

    LineToPointCachingAdapter(Line& line) {
        boost::hash<Line> hash;
        line_hash = hash(line);
        if (cache.find(line_hash) != cache.end()) return;

        static int count = 0;
        cout << count << " generating points to line caching" << endl;
        Points points;
        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;
        // Vertical
        if (dx == 0) {
            for (int idx = top; idx <= bottom; ++idx) {
                points.emplace_back(Point{left, idx});
            }
        } else if (dy == 0) {
            for (int idx = left; idx <= right ; ++idx) {
                points.emplace_back(Point{idx, top});
            }
        }
        cache[line_hash] = points;
    }
    virtual Points::iterator begin() {
        return cache[line_hash].begin();
    }
    virtual Points::iterator end() {
        return cache[line_hash].end();
    }
private:
    size_t line_hash;
    static std::map<size_t, vector<Point>> cache;
};

std::map<size_t, vector<Point>> LineToPointCachingAdapter::cache;
#endif //ADAPTER_GEOMETRY_H
