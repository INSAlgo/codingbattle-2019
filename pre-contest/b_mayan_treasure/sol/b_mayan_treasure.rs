use std::io;

fn read_int() -> i32 {
    // I don't check errors since we are in a contest.
    // Moreover, using the crate text_io can reduce
    // all this code to a simple read!(), but it's not
    // available during contests.

    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim().parse::<i32>().unwrap()
}

fn read_ints() -> Vec<i32> {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line.trim().split(' ').flat_map(str::parse).collect()
}

fn main() {
    let n = read_int() as usize;

    let mut array = read_ints();
    array.sort();

    let (r, _) = (0..n-2)
        .map(|i| (i, array[i + 2] - array[i]))
        .min_by_key(|(_, x)| *x)
        .unwrap();

    println!("{} {} {}", array[r], array[r + 1], array[r + 2]);
}

