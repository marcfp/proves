#include <chrono>
#include <cstdio>
using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{
  size_t N = 1e6;
  if(2 == argc) {
    sscanf(argv[1], "%zu", &N);
  }

#if defined(hrc)
  typedef high_resolution_clock clock;
#warning "High resolution clock"
#elif defined(sc)
  typedef steady_clock clock;
#warning "Steady clock"
#elif defined(sys)
  typedef system_clock clock;
#warning "System clock"
#endif

  const double resolution = double(clock::period::num) / double(clock::period::den);

  printf("clock::period: %lf us.\n", resolution*1e6);
  printf("clock::is_steady: %s\n", clock::is_steady ? "yes" : "no");
  printf("Calling clock::now() %zu times...\n", N);

  // first, warm up
  for(size_t i=0; i<100; ++i) {
    time_point<clock> t = clock::now();
  }

  // loop N times
  time_point<clock> start = clock::now();
  for(size_t i=0; i<N; ++i) {
    time_point<clock> t = clock::now();
  }
  time_point<clock> end = clock::now();

  // display duration
  duration<double> time_span = duration_cast<duration<double>>(end-start);
  const double sec = time_span.count();
  const double ns_it = sec*1e9/N;
  printf("That took %lf seconds. That's %lf ns/iteration.\n", sec, ns_it);

  return 0;
}
