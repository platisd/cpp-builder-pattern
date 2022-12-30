#include <string>
#include <vector>

namespace
{
class Menu
{
public:
    static Menu create(std::string id)
    {
        return Menu{id};
    }
    void show() const {}
    void select(int /* index */) const {}

    Menu& withTitle(std::string title)
    {
        mTitle = title;
        return *this;
    }

    Menu& withBorder(int pixels)
    {
        mBorder = pixels;
        return *this;
    }

    Menu& addOption(std::string option)
    {
        mOptions.emplace_back(option);
        return *this;
    }

    Menu& horizontal()
    {
        mHorizontal = true;
        return *this;
    }

    Menu& vertical()
    {
        mHorizontal = false;
        return *this;
    }

private:
    std::string mId{};
    std::string mTitle{};
    std::vector<std::string> mOptions{};
    bool mHorizontal{false};
    int mBorder{0};

    Menu(std::string id)
        : mId{id}
    {
    }
};
} // namespace

int main()
{
    const auto menu = Menu::create("main")
                          .withTitle("Main Menu")
                          .withBorder(1)
                          .addOption("Option 1")
                          .addOption("Option 2")
                          .horizontal();
    menu.show();
    menu.select(1);
    return 0;
}
