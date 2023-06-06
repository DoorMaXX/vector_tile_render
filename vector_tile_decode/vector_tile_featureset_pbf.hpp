#pragma once

#include <protozero/pbf_reader.hpp>

#include <mapnik/feature.hpp>
#include <mapnik/featureset.hpp>
#include <mapnik/unicode.hpp>
#include <mapnik/util/variant.hpp>
#include <mapnik/view_transform.hpp>

#include <set>

namespace mapnik
{

namespace vector_tile_impl
{

using pbf_attr_value_type = mapnik::util::variant<std::string, float, double, int64_t, uint64_t, bool>;
using layer_pbf_attr_type = std::vector<pbf_attr_value_type>;

template <typename Filter>
class tile_featureset_pbf : public Featureset
{
public:
    tile_featureset_pbf(Filter const& filter,
                    mapnik::box2d<double> const& tile_extent,
                    mapnik::box2d<double> const& unbuffered_query,
                    std::set<std::string> const& attribute_names,
                    std::vector<protozero::pbf_reader> const& features,
                    double tile_x,
                    double tile_y,
                    double scale,
                    std::vector<std::string> const& layer_keys,
                    layer_pbf_attr_type const& layer_values,
                    unsigned version);

    virtual ~tile_featureset_pbf() {}

    feature_ptr next();

    int32_t get_geometry_type(){return geometry_type;}

private:
    Filter filter_;
    mapnik::box2d<double> tile_extent_;
    mapnik::box2d<double> unbuffered_query_;
    std::vector<protozero::pbf_reader> const& features_;
    std::vector<std::string> const& layer_keys_;
    layer_pbf_attr_type const& layer_values_;
    std::size_t num_keys_;
    std::size_t num_values_;
    double tile_x_;
    double tile_y_;
    double scale_;
    unsigned itr_;
    unsigned version_;
    mapnik::transcoder tr_;
    mapnik::context_ptr ctx_;
    int32_t geometry_type = 0;
};

} // end ns vector_tile_impl

} // end ns mapnik

