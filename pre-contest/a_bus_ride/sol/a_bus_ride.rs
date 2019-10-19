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

fn main() {
    let nb_person = read_int();
    let nb_seat = read_int();

    let result = (nb_person as f32 / nb_seat as f32).ceil();

    println!("{}", result);
}

