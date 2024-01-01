#include <memory>
#include <string>
#include <vector>

namespace
{
class Menu
{
public:
    class Builder
    {
    public:
        Builder(std::string id)
            : mMenu{new Menu{id}}
        {
        }

        Builder& withTitle(std::string title)
        {
            mMenu->mTitle = title;
            return *this;
        }
        Builder& withBorder(int pixels)
        {
            mMenu->mBorder = pixels;
            return *this;
        }
        Builder& addOption(std::string o)
        {
            mMenu->mOpts.push_back(o);
            return *this;
        }
        Builder& horizontal()
        {
            mMenu->mHorizontal = true;
            return *this;
        }
        Builder& vertical()
        {
            mMenu->mHorizontal = false;
            return *this;
        }

        std::unique_ptr<Menu> build()
        {
            return std::move(mMenu);
        }

    private:
        std::unique_ptr<Menu> mMenu{};
    };

    void show() const {}
    void select(int /* index */) const {}

private:
    std::string mId{};
    std::string mTitle{};
    std::vector<std::string> mOpts{};
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
    const auto menu = Menu::Builder{"main"}
                          .withTitle("Main Menu")
                          .withBorder(1)
                          .addOption("Option 1")
                          .addOption("Option 2")
                          .horizontal()
                          .build();
    menu->show();
    menu->select(1);

    return 0;
}
