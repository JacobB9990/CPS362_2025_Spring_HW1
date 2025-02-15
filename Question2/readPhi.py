import sys

# Checks if pandas and matplotlib are installed...
try:
    import pandas as pd
    import matplotlib.pyplot as plt
except ModuleNotFoundError as e:
    print(f"Error: {e}")
    print("Please install the required modules using the following commands:")
    print("pip(3) install pandas matplotlib")
    sys.exit(1)


def main(n):
    try:
        filename = f"calculating_{n}th_phi.csv"
        data = pd.read_csv(filename)

        print("Data from CSV:")
        print(data)

        plt.figure(figsize=(10, 6))

        # Delta
        plt.plot(
            data["n"],
            data["Delta"],
            label="Delta",
        )

        # plt.plot(
        #     data["n"],
        #     data["Iterative_float"],
        #     label="Iterative (float)",
        # )

        # plt.plot(
        #     data["n"],
        #     data["Iterative_double"],
        #     label="Iterative (double)",
        # )

        plt.xlabel("n")
        plt.ylabel("Value")
        plt.title(
            f'Comparison of Straightforward and Iterative Calculations for φ^n (n up to {data["n"].max()})'
        )
        plt.legend()
        plt.grid(True)
        plt.show()

    except KeyboardInterrupt:
        print("Exiting\n")
        sys.exit(0)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python readPhi.py <nth_term>")
        sys.exit(1)

    nth_term = int(sys.argv[1])
    main(nth_term)
