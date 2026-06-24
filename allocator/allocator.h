#ifndef ALLOCATOR_H
#define ALLOCATOR_H

template < class T >
struct allocator{
    public:
      // value for allocator_traits
      using value_type = T;

      // default construtor, compile time
      constexpr allocator() noexcept = default;

      // copy constructor template for implicit copies and rebinding from class U to T when using allocator_trait
      template < class U >
      allocator(const allocator<U> &) noexcept {}

      // allocate function to allocate unitialized memory
      constexpr T* allocate(std::size_t);

      // deallocate function to deallocate memory
      constexpr void deallocate(T*, std::size_t);

};

// allocator comparison functions
template < typename T, typename U >
constexpr bool operator==(const allocator<T>&, const allocator<U>&) noexcept;

template < typename T, typename U >
constexpr bool operator!=(const allocator<T>&, const allocator<U>&) noexcept;

#endif //ALLOCATOR_H