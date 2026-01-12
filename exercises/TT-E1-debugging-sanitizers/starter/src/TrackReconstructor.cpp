#include "TrackReconstructor.hpp"

#include <iostream>

namespace tt_e1 {

TrackReconstructor::TrackReconstructor(double minPt) : m_minPt(minPt) {}

void TrackReconstructor::addHit(const Hit& hit) { m_hits.push_back(hit); }

std::vector<Track> TrackReconstructor::reconstruct() {
    std::vector<Track> tracks;

    // Allocate a temporary buffer
    Hit* hitBuffer = new Hit[m_hits.size()];

    // Copy hits to buffer
    for (size_t i = 0; i < m_hits.size(); ++i) {
        hitBuffer[i] = m_hits[i];
    }

    // Simulate "reconstruction"
    if (!m_hits.empty()) {
        Track t{};
        t.pt = 10.0;          // fake pT
        t.hits = m_hits;      // copy hits
        tracks.push_back(t);
    }

    // Clean up
    delete[] hitBuffer;

    return tracks;
}

// Return the best track (simulated)
const Track* TrackReconstructor::getBestTrack() const {
    auto* best = new Track{};
    best->pt = 100.0;
    best->hits = m_hits;

    // Note: In a real implementation, the caller would be responsible for deleting this.
    return best;
}

} // namespace tt_e1

