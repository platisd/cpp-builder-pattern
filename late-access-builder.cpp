#include <memory>
#include <string>
#include <vector>

namespace
{
class Menu
{
public:
    class Impl
    {
    public:
        void show() const {}
        void select(int /* index */) const {}

    private:
        friend class Menu;

        std::string mId{};
        std::string mTitle{};
        std::vector<std::string> mOptions{};
        bool mHorizontal{false};
        int mBorder{0};

        Impl(std::string id)
            : mId{id}
        {
        }
    };

    Menu(std::string id)
        : mImpl{new Impl{id}}
    {
    }

    std::unique_ptr<Impl> build()
    {
        return std::move(mImpl);
    }

    Menu& withTitle(std::string title)
    {
        mImpl->mTitle = title;
        return *this;
    }

    Menu& withBorder(int pixels)
    {
        mImpl->mBorder = pixels;
        return *this;
    }

    Menu& addOption(std::string option)
    {
        mImpl->mOptions.emplace_back(option);
        return *this;
    }

    Menu& horizontal()
    {
        mImpl->mHorizontal = true;
        return *this;
    }

    Menu& vertical()
    {
        mImpl->mHorizontal = false;
        return *this;
    }

private:
    std::unique_ptr<Impl> mImpl{};
};
} // namespace

int main()
{
    const auto menu = Menu{"main"}
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
