<h1 align="center">
	42-Philosophers
</h1>

<p align="center">
    <img src="https://github.com/user-attachments/assets/05e2e3ec-c64b-43df-b58f-71ede0f9c893">
</p>

<p align="center">
	<b><i>Development repo for 42cursus philosophers project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/MarkosComK/42-Common-Core-Guide"><b>42-Common-Core-Guide repo</b></a>.
</p>

<!---
<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>
--->
<br>
<div align="center">
	<img src="https://github.com/MarkosComK/42-Libft/assets/67120870/10a2a298-340e-4a67-96bd-d97716a60526">
</div>

## This is a project in daily use. If you want to see the project that i have been evaluated in 42school click in releases at the right side!

## 🗣️ About

> _The aim of this project is understand the cre concepts envolving threads by solving the <a src="https://en.wikipedia.org/wiki/Dining_philosophers_problem">Dining philosophers problem</a>._

<br>

# Great Resources for Philosophers

[Little Book Of Semaphores.pdf](https://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf)

[Codevault - Youtube](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) 

[Learn C](https://www.learn-c.org/)

[C-Programming-Language-2nd-Edition (PDF)](https://github.com/MarkosComK/42-Libft/files/14312769/C-Programming-Language-2nd-Edition.pdf)

For detailed information, refer to the [subject of the project](https://github.com/user-attachments/files/17247774/en.subject.pdf)

	🚀 This project consists of solving the famous Dijkstra dining problem, which involves
    the usage of threads, mutexes and, also, processes.

## 🛠️ Usage

### Requirements

The library is written in C language and thus requires the **`gcc` compiler** and standard **C libraries** to run.

### Instructions

**1. Compiling the `philo`**

To compile the philosophers project, run:

```shell
$ cd path/to/philo && make
```

## 📋 Testing

Before testing, it's essential to understand what each parameter in the command line means:

### Command Line Arguments

When running the `philo` program, you'll use the following command structure:

```shell
$ ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- **`number_of_philosophers`**: The number of philosophers in the simulation.
- **`time_to_die`** (in ms): The maximum time a philosopher can go without eating. If this time passes, the philosopher dies.
- **`time_to_eat`** (in ms): The time it takes for a philosopher to eat once they have both forks.
- **`time_to_sleep`** (in ms): The time a philosopher spends sleeping after eating.
- **`number_of_times_each_philosopher_must_eat`** (optional): The simulation stops when each philosopher has eaten at least this number of times. If this argument is omitted, the simulation runs indefinitely until a philosopher dies.

### Testing Scenarios

You can test the philosophers' behavior with various scenarios to ensure that the logic works as expected. Here are some examples and what you should observe:

---

**1. `./philo 1 800 200 200`**

- **Description**: You have 1 philosopher, and their `time_to_die` is set to 800 ms, while the `time_to_eat` and `time_to_sleep` are both 200 ms.
- **Expected Behavior**: The philosopher should not be able to eat, as there's only one philosopher and hence only one fork. The philosopher will die after 800 ms because they cannot acquire two forks to eat.

---

**2. `./philo 5 800 200 200`**

- **Description**: There are 5 philosophers, and each has a `time_to_die` of 800 ms, `time_to_eat` of 200 ms, and `time_to_sleep` of 200 ms.
- **Expected Behavior**: No philosopher should die. They should continuously take turns eating and sleeping.

---

**3. `./philo 5 800 200 200 7`**

- **Description**: There are 5 philosophers, and the simulation is set to stop when each philosopher has eaten at least 7 times.
- **Expected Behavior**: No philosopher should die. The simulation will stop when each philosopher has eaten 7 times.

---

**4. `./philo 4 410 200 200`**

- **Description**: 4 philosophers with `time_to_die` set to 410 ms, `time_to_eat` to 200 ms, and `time_to_sleep` to 200 ms.
- **Expected Behavior**: No philosopher should die since there is enough time for each philosopher to eat before the `time_to_die` runs out.

---

**5. `./philo 4 310 200 100`**

- **Description**: 4 philosophers with a `time_to_die` of 310 ms, `time_to_eat` of 200 ms, and `time_to_sleep` of 100 ms.
- **Expected Behavior**: One philosopher will die because the time left between eating and dying is too short for all the philosophers to complete the eating and sleeping cycles in time.

---

**6. `./philo 2 <various times>`**

- **Description**: Use 2 philosophers with different `time_to_die`, `time_to_eat`, and `time_to_sleep` values to test edge cases.
- **Expected Behavior**: Test for accurate death timing. A death delayed by more than 10 ms is unacceptable in these tests.

---

### Testing Guidelines

- **Do not test with more than 200 philosophers**, as it may result in undefined behavior due to system limitations or constraints on thread management.
- **Avoid setting `time_to_die`, `time_to_eat`, or `time_to_sleep` to values lower than 60 ms**, as such small time values could cause unexpected behavior due to the operating system's task scheduling limits.

### Test and Verify:

- Ensure philosophers **die at the correct time**.
- Check that philosophers **do not steal forks** (i.e., no two philosophers can hold the same fork simultaneously).
- Verify that the **time intervals** between eating, sleeping, and dying match the expected values based on the input parameters.

By running these tests, you'll ensure that your simulation meets the project’s requirements and behaves as expected under various scenarios.

---

### Third-party Testers

I haven't written a custom tester yet, but you can make your own tests for each function. Here are some third-party testers that you can use:

* [LazyPhilosophersTester](https://github.com/MichelleJiam/LazyPhilosophersTester)
* [Philosphers-42Project-Tester](https://github.com/newlinuxbot/Philosphers-42Project-Tester)

These tools can help verify the correctness and performance of your philosopher simulation.
