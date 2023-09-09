#include <vector>
#include <array>
#include <iostream>
#include <chrono>
#include <functional>
#include <benchmark/benchmark.h>

#pragma pack(push, 1)
struct Item {
    uint16_t id;
    int64_t cost;
};

struct Struct {
    uint16_t id;
    std::array<char, 5> name;
    uint64_t cost;
    std::array<int64_t, 3> field_1;
    std::array<Item, 2> field_2;
};
#pragma pack(pop)

char* getBinData() {
    Struct* data = new Struct();
    data->id = 1003;
    data->name = {'A', 'B', 'C', 'D', 'E'};
    data->cost = 212314128234234;
    data->field_1 = {12310, 8923, 28899};
    data->field_2 = {Item{100, 1238189}, Item{200, 99999999999}};
    return reinterpret_cast<char*>(data);
}

void cast_whole_struct(char* binary_data) {
    Struct s = *reinterpret_cast<Struct*>(binary_data);
}

static void BM_CastWholeString(benchmark::State& state) {
    char* binary_data = getBinData();
    for (auto _ : state) {
        cast_whole_struct(binary_data);
    }
    delete binary_data;
}

void cast_each_member(char* binary_data) {
    Struct s;
    s.id = *reinterpret_cast<uint16_t*>(binary_data);
    binary_data += sizeof(s.id);
    s.name = *reinterpret_cast<std::array<char, 5>*>(binary_data);
    binary_data += sizeof(s.name);
    s.cost = *reinterpret_cast<uint64_t*>(binary_data);
    binary_data += sizeof(s.cost);
    s.field_1 = *reinterpret_cast<std::array<int64_t, 3>*>(binary_data);
    binary_data += sizeof(s.field_1);

    for(size_t i = 0; i < 2; ++i) {
        s.field_2[i].id = *reinterpret_cast<uint16_t*>(binary_data);
        binary_data += sizeof(s.field_2[i].id);
        s.field_2[i].cost = *reinterpret_cast<int64_t*>(binary_data);
        binary_data += sizeof(s.field_2[i].cost);
    }
}

static void BM_CastEachMember(benchmark::State& state) {
    char* binary_data = getBinData();
    for (auto _ : state) {
        cast_each_member(binary_data);
    }
    delete binary_data;
}


BENCHMARK(BM_CastWholeString);
BENCHMARK(BM_CastEachMember);
BENCHMARK_MAIN();
